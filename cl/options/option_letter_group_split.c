void __cdecl option_letter_group_split(letters *g,char *sw)

{
  byte c;
  size_t prefix_len;
  char *p_2;
  int rc;
  char *p;
  byte *in;
  byte *out;
  char text [32];
  char *single_argv [2];
  int index;
  byte c_2;
  
  single_argv[0] = text;
  single_argv[1] = (char *)0x0;
  text[0] = *sw;
  p = sw + 1;
  prefix_len = strlen(g->prefix);
  memcpy(text + 1,p,prefix_len);
  c = p[prefix_len];
  in = (byte *)(p + prefix_len);
  if (c == 0) {
    return;
  }
LAB_004023b0:
  p_2 = strchr(g->letters,(uint)c);
  text[prefix_len + 1] = *in;
  out = (byte *)(text + prefix_len + 1 + 1);
  in = in + 1;
  if (p_2 != (char *)0x0) {
    while( true ) {
      c_2 = p_2[1];
      p_2 = p_2 + 1;
      if ((c_2 == 0x3a) || (c_2 == 0)) break;
      if (c_2 == 0x23) {
        while (rc = isdigit((uint)*in), rc != 0) {
          *out = *in;
          out = out + 1;
          in = in + 1;
        }
      }
      else {
        if (c_2 == 0x2a) goto LAB_00402408;
        if (c_2 != *in) break;
        *out = *in;
        out = out + 1;
        in = in + 1;
      }
    }
  }
  goto LAB_00402414;
LAB_00402408:
  for (; *in != 0; in = in + 1) {
    *out = *in;
    out = out + 1;
  }
LAB_00402414:
  *out = 0;
  index = 0;
  option_apply(single_argv,&index,1);
  c = *in;
  if (c == 0) {
    return;
  }
  goto LAB_004023b0;
}

