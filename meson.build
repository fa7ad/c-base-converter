project('c-base-converter', 'c', default_options: ['c_std=c11'])

app = 'base_converter'
cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required: false)

executable(app, 'main.c', dependencies: m_dep)
