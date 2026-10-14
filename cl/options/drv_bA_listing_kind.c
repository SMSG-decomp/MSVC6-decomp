void __cdecl drv_bA_listing_kind(optrec *r)

{
  byte c;
  optrec *FA_pattern;
  optrec *Fa_pattern;
  optrec *Fa;
  char *p;
  char *p_2;
  char *p_3;
  char *p_4;
  byte *q;
  optrec *FA;
  byte *kinds;
  bool with_code;
  bool bad;
  uchar *value;
  
  value = (uchar *)r->value;
  if (*value == '\0') {
    return;
  }
  kinds = _mbschr(value,0x20);
  if (kinds != (byte *)0x0) {
    *kinds = 0;
    kinds = kinds + 1;
  }
  FA_pattern = optrec_new("FA","?",(char *)value,'\x04');
  Fa_pattern = optrec_new("Fa","?",(char *)value,'\0');
  FA = optrec_list_extract_matching(&g_driver_ctx_ptr->pass_options,FA_pattern,(optrec **)0x0);
  Fa = optrec_list_extract_matching(&g_driver_ctx_ptr->pass_options,Fa_pattern,(optrec **)0x0);
  if (FA == (optrec *)0x0) {
    xfree(FA_pattern->value);
    p = xstrdup((char *)kinds);
    FA_pattern->value = p;
    FA = FA_pattern;
  }
  else {
    kinds = (byte *)FA->value;
    optrec_free(FA_pattern);
  }
  if (Fa == (optrec *)0x0) {
    xfree(Fa_pattern->value);
    p_2 = xstrdup("%b");
    Fa_pattern->value = p_2;
  }
  else {
    optrec_free(Fa_pattern);
    Fa_pattern = Fa;
  }
  strcpy(g_scratch,Fa_pattern->value);
  bad = false;
  with_code = false;
  if ((kinds != (byte *)0x0) && (c = *kinds, q = kinds, c != 0)) {
    do {
      if (c < 0x61) {
LAB_00402c13:
        bad = true;
      }
      else if (0x62 < c) {
        if (c == 99) {
          with_code = true;
        }
        else if (c != 0x73) goto LAB_00402c13;
      }
      c = q[1];
      q = q + 1;
    } while (c != 0);
    if (bad) {
      cl_warning(0xfaf,"/FA",kinds + 1);
    }
    p_3 = "cod";
    if (with_code) goto LAB_00402c46;
  }
  p_3 = "asm";
LAB_00402c46:
  path_set_default_extension(p_3,g_scratch,(char *)0x0);
  xfree(Fa_pattern->value);
  p_4 = xstrdup(g_scratch);
  Fa_pattern->value = p_4;
  list_append(&g_driver_ctx_ptr->pass_options,FA);
  list_append(&g_driver_ctx_ptr->pass_options,Fa_pattern);
  *r->value = '\0';
  return;
}

