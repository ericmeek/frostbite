def finally_do
  put "dir stop"
end

def directions
  put "dir #{$args.join(" ")} 100"
  m = match_get({ :go => [/Directions towards|don't know the way|Here are all the places/] })
  m[:match].gsub(/.*:/, '').split(/,|\band\b/).collect(&:strip)
end

directions.each do |dir|
  if dir =~ /west|south|north|east|go|out|climb/i
    move dir.downcase
  end
end