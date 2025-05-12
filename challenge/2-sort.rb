#!/usr/bin/env ruby
###
#
#  Sort integer arguments (ascending)
#
###

result = []

# Collect only valid integers from ARGV
ARGV.each do |arg|
  next unless arg =~ /^-?\d+$/  # Regex for optional negative sign and digits
  result << arg.to_i
end

# Sort and print the result
puts result.sort
