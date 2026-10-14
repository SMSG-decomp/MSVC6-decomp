letters * __cdecl option_letter_group_lookup(char *sw)

{
  int match;
  char **letters;
  int i;
  
  i = 0;
  letters = &g_option_letter_groups[0].letters;
  do {
    match = str_has_prefix(letters[-1],sw);
    if (match != 0) {
      return g_option_letter_groups + i;
    }
    letters = letters + 2;
    i = i + 1;
  } while (*letters != (char *)0x0);
  return (letters *)0x0;
}

