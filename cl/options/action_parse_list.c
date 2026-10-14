optrec * __cdecl action_parse_list(char *actions,optrec *opt)

{
  char *p;
  char *p_2;
  char *dst_2;
  size_t len;
  optrec *rec;
  char c;
  char *dst;
  char name [32];
  char passes [20];
  optrec *list;
  char c_2;
  char c_3;
  
  list = (optrec *)0x0;
  passes[0] = '\0';
  c_2 = *actions;
  p_2 = actions;
  do {
    if (c_2 == '\0') {
      return list;
    }
    actions._0_1_ = 0;
    p = str_skip_spaces(p_2);
    c = *p;
    if (c == '\0') {
      return list;
    }
    if ((((c != '=') && (c != '#')) && (c != '-')) && (c != '~')) {
      dst = passes;
      do {
        if (((c == '#') || (c == '-')) || (c == '~')) break;
        *dst = c;
        c = p[1];
        dst = dst + 1;
        p = p + 1;
      } while (c != '=');
      *dst = '\0';
    }
    c_3 = *p;
    if (c_3 == '#') {
      actions._0_1_ = 8;
    }
    else if (c_3 == '-') {
      actions._0_1_ = 1;
    }
    else if (c_3 == '~') {
      actions._0_1_ = 0x10;
    }
    p_2 = action_expand_value(p + 1,name,opt->name);
    if (*p_2 == '!') {
      actions._0_1_ = (byte)actions | 4;
LAB_0040172f:
      p_2 = action_expand_value(p_2 + 1,g_scratch,opt->value);
      len = strlen(g_scratch);
      dst_2 = (char *)(-(uint)(len != 0) & 0x40b228);
    }
    else {
      if (*p_2 == ':') goto LAB_0040172f;
      dst_2 = (char *)0x0;
    }
    if (*p_2 == ',') {
      p_2 = p_2 + 1;
    }
    rec = optrec_new(name,dst_2,passes,(byte)actions);
    list_append(&list,rec);
    c_2 = *p_2;
  } while( true );
}

