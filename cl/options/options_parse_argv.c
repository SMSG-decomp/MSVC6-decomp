void __cdecl options_parse_argv(char **argv,int argc)

{
  int type;
  letters *g;
  size_t prefix_len;
  short explicit_type;
  int i;
  int files_before;
  char c;
  char *word_2;
  char *word;
  
  i = 0;
  if (0 < argc) {
    do {
      files_before = g_compilable_files;
      word = argv[i];
      c = *word;
      if (c == '@') {
        response_file_read(word + 1);
        i = i + 1;
      }
      else {
        if ((c == '-') || (c == '/')) {
          g = option_letter_group_lookup(word + 1);
          if (g == (letters *)0x0) {
LAB_004022c2:
            option_apply(argv,&i,1);
          }
          else {
            word_2 = argv[i];
            prefix_len = strlen(g->prefix);
            if (word_2[prefix_len + 1] == '\0') goto LAB_004022c2;
            i = i + 1;
            option_letter_group_split(g,word_2);
          }
          if ((g_compilable_files != 0) && (files_before == g_compilable_files)) {
            g_switch_after_file = 1;
          }
        }
        else {
          explicit_type = 0;
          type = file_type_from_extension(word);
          srcfile_append(argv[i],type,explicit_type);
          i = i + 1;
        }
        if (((g_switch_after_file != 0) && (files_before != g_compilable_files)) &&
           (g_D4026_issued == 0)) {
          cl_warning(0xfba);
          g_D4026_issued = 1;
        }
      }
    } while (i < argc);
  }
  return;
}

