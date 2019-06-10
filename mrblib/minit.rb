module Minit
  def bye
    self.hello + " bye"
  end
end

def __main__(argv)
  puts "version: #{Minit::VERSION}"
end
