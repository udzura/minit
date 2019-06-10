##
## Minit Test
##

assert("Minit#hello") do
  t = Minit.new "hello"
  assert_equal("hello", t.hello)
end

assert("Minit#bye") do
  t = Minit.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Minit.hi") do
  assert_equal("hi!!", Minit.hi)
end
