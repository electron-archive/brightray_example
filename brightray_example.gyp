{
  'variables': {
    'project_name': 'brightray_example',
    'product_name': 'Brightray Example',
    'app_sources': [
      'common/main.cc',
    ],
    'lib_sources': [
      'browser/browser_client.cc',
      'browser/browser_client.h',
      'browser/browser_main_parts.cc',
      'browser/browser_main_parts.h',
      'browser/mac/window_controller.mm',
      'browser/mac/window_controller.h',
      'browser/mac/window_mac.h',
      'browser/mac/window_mac.mm',
      'browser/win/window_win.cc',
      'browser/win/window_win.h',
      'browser/window.cc',
      'browser/window.h',
      'common/main_delegate.cc',
      'common/main_delegate.h',
      'renderer/render_view_observer.cc',
      'renderer/render_view_observer.h',
      'renderer/renderer_client.cc',
      'renderer/renderer_client.h',
    ],
    'framework_sources': [
      'common/library_main.cc',
      'common/library_main.h',
    ],
    'conditions': [
      ['OS=="win"', {
        'app_sources': [
          '<(libchromiumcontent_src_dir)/content/app/startup_helper_win.cc',
        ],
      }],
    ],
  },
  'includes': [
    'vendor/brightray/brightray.gypi',
  ],
  'targets': [
    {
      'target_name': '<(project_name)',
      'type': 'executable',
      'dependencies': [
        '<(project_name)_lib',
      ],
      'sources': [
        '<@(app_sources)',
      ],
      'conditions': [
        ['OS=="mac"', {
          'product_name': '<(product_name)',
          'mac_bundle': 1,
          'dependencies!': [
            '<(project_name)_lib',
          ],
          'dependencies': [
            '<(project_name)_framework',
            '<(project_name)_helper',
          ],
          'xcode_settings': {
            'INFOPLIST_FILE': 'browser/mac/Info.plist',
            'LD_RUNPATH_SEARCH_PATHS': '@executable_path/../Frameworks',
          },
          'copies': [
            {
              'destination': '<(PRODUCT_DIR)/<(product_name).app/Contents/Frameworks',
              'files': [
                '<(PRODUCT_DIR)/<(product_name) Helper.app',
                '<(PRODUCT_DIR)/<(product_name).framework',
              ],
            },
          ],
          'postbuilds': [
            {
              # This postbuid step is responsible for creating the following
              # helpers:
              #
              # <(product_name) EH.app and <(product_name) NP.app are created
              # from <(product_name).app.
              #
              # The EH helper is marked for an executable heap. The NP helper
              # is marked for no PIE (ASLR).
              'postbuild_name': 'Make More Helpers',
              'action': [
                'vendor/brightray/tools/mac/make_more_helpers.sh',
                'Frameworks',
                '<(product_name)',
              ],
            },
          ]
        }],
        ['OS=="win"', {
          'copies': [
            {
              'destination': '<(PRODUCT_DIR)',
              'files': [
                '<(libchromiumcontent_library_dir)/chromiumcontent.dll',
                '<(libchromiumcontent_library_dir)/icudt.dll',
                '<(libchromiumcontent_library_dir)/libGLESv2.dll',
              ],
            },
          ],
        }],
      ],
    },
    {
      'target_name': '<(project_name)_lib',
      'type': 'static_library',
      'dependencies': [
        'vendor/brightray/brightray.gyp:brightray',
      ],
      'sources': [
        '<@(lib_sources)',
      ],
      'include_dirs': [
        '.',
      ],
      'direct_dependent_settings': {
        'include_dirs': [
          '.',
        ],
      },
      'export_dependent_settings': [
        'vendor/brightray/brightray.gyp:brightray',
      ],
      'conditions': [
        ['OS!="mac"', {
          'sources/': [
            ['exclude', '/mac/'],
            ['exclude', '_mac\.(mm|h)$'],
          ],
        }],
        ['OS!="win"', {
          'sources/': [
            ['exclude', '/win/'],
            ['exclude', '_win\.(cc|h)$'],
          ],
        }],
      ],
    },
  ],
  'conditions': [
    ['OS=="mac"', {
      'targets': [
        {
          'target_name': '<(project_name)_framework',
          'product_name': '<(product_name)',
          'type': 'shared_library',
          'dependencies': [
            '<(project_name)_lib',
          ],
          'sources': [
            '<@(framework_sources)',
          ],
          'mac_bundle': 1,
          'mac_bundle_resources': [
            'browser/mac/MainMenu.xib',
            'browser/mac/WindowController.xib',
            '<(libchromiumcontent_resources_dir)/content_shell.pak',
          ],
          'xcode_settings': {
            'LIBRARY_SEARCH_PATHS': '<(libchromiumcontent_library_dir)',
            'LD_DYLIB_INSTALL_NAME': '@rpath/<(product_name).framework/<(product_name)',
            'LD_RUNPATH_SEARCH_PATHS': '@loader_path/Libraries',
            'OTHER_LDFLAGS': [
              '-ObjC',
            ],
          },
          'copies': [
            {
              'destination': '<(PRODUCT_DIR)/<(product_name).framework/Versions/A/Libraries',
              'files': [
                '<(libchromiumcontent_library_dir)/ffmpegsumo.so',
                '<(libchromiumcontent_library_dir)/libchromiumcontent.dylib',
              ],
            },
          ],
          'export_dependent_settings': [
            '<(project_name)_lib',
          ],
        },
        {
          'target_name': '<(project_name)_helper',
          'product_name': '<(product_name) Helper',
          'type': 'executable',
          'dependencies': [
            '<(project_name)_framework',
          ],
          'sources': [
            '<@(app_sources)',
          ],
          'mac_bundle': 1,
          'xcode_settings': {
            'INFOPLIST_FILE': 'renderer/mac/Info.plist',
            'LD_RUNPATH_SEARCH_PATHS': '@executable_path/../../../../Frameworks',
          },
        },
      ],
    }],
  ],
}
