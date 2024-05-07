file(REMOVE_RECURSE
  "sim"
  "sim.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sim.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
