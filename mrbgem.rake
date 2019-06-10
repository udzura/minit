require_relative 'mrblib/minit/version'

MRuby::Gem::Specification.new('minit') do |spec|
  spec.bins = ['minit']

  spec.add_dependency 'mruby-io', core: 'mruby-io'
  spec.add_dependency 'mruby-print', core: 'mruby-print'

  spec.license = 'MIT'
  spec.authors = 'Uchio Kondo'
  spec.version = Minit::VERSION
end
