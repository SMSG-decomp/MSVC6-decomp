int __cdecl option_pattern_match_length(optdesc *desc,char **argv,int index)

{
  int len;
  char *pat;
  char *sw;
  char c;
  
  pat = desc->pattern;
  sw = argv[index] + 1;
  if (*pat != '^') goto LAB_00401523;
  if (g_parsing_defaults != 0) {
    while( true ) {
      pat = pat + 1;
LAB_00401523:
      c = *pat;
      if ((c == ':') || (c == '!')) break;
      if (c != *sw) {
        return 0;
      }
      if (c == '\0') break;
      sw = sw + 1;
    }
    len = (int)sw - (int)argv[index];
    if (*pat != '\0') {
      return len;
    }
    if (*sw == ' ') {
      return len;
    }
    if (*sw == '\0') {
      return len;
    }
  }
  return 0;
}

