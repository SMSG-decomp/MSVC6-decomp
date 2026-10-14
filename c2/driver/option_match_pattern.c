int __fastcall
option_match_pattern(c2_option_row *table,char *arg,c2_next_argument_fn *next_argument,int copy)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  c2_option_row *pcVar4;
  int iVar5;
  char *pattern;
  char *arg_00;
  
  if (arg != (char *)0x0) {
    bVar1 = table->kind;
    g_option_current_argument = arg;
    while (bVar1 != 0) {
      pattern = table->pattern;
      arg_00 = arg;
LAB_10757b45:
      do {
        cVar2 = *pattern;
        switch(cVar2) {
        case '\0':
          if (*arg_00 == '\0') {
            if ((table->kind & 0x20) != 0) {
              g_option_next_word = (*next_argument)();
              option_store_value(table,g_option_next_word,copy);
              return (uint)table->result;
            }
            option_store_value(table,(char *)0x0,copy);
            return (uint)table->result;
          }
          goto LAB_10757b57;
        case '#':
          if (*arg_00 == '\0') {
            g_option_next_word = (*next_argument)();
            option_store_value(table,g_option_next_word,copy);
            return (uint)table->result;
          }
          option_store_value(table,arg_00,copy);
          return (uint)table->result;
        case '*':
          if ((*arg_00 != '\0') &&
             (iVar5 = option_match_suffix(pattern,arg_00,(uint)bVar1), iVar5 != 0)) {
            option_store_value(table,arg_00,copy);
            return (uint)table->result;
          }
          goto LAB_10757b57;
        case '-':
          if (*arg_00 != '-') goto LAB_10757b57;
          arg_00 = arg_00 + 1;
          pattern = pattern + 1;
          goto LAB_10757b45;
        }
        cVar3 = *arg_00;
        arg_00 = arg_00 + 1;
        pattern = pattern + 1;
      } while (cVar2 == cVar3);
LAB_10757b57:
      pcVar4 = table + 1;
      table = table + 1;
      bVar1 = pcVar4->kind;
    }
  }
  return 0;
}

