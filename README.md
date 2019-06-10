# minit   [![Build Status](https://travis-ci.org/udzura/minit.svg?branch=master)](https://travis-ci.org/udzura/minit)
Minit class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'udzura/minit'
end
```
## example
```ruby
p Minit.hi
#=> "hi!!"
t = Minit.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
