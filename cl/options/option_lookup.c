optdesc * __cdecl option_lookup(char **argv,int index)

{
  int len;
  cl_optdesc *desc;
  optdesc *best;
  int best_len;
  
  best_len = 0;
  best = (optdesc *)0x0;
  desc = g_option_table;
  do {
    if (((desc->pattern[*desc->pattern == '^'] == argv[index][1]) &&
        (len = option_pattern_match_length(desc,argv,index), 0 < len)) &&
       ((best_len == 0 || (best_len < len)))) {
      best = desc;
      best_len = len;
    }
    desc = desc + 1;
  } while (desc->pattern != (char *)0x0);
  return best;
}

