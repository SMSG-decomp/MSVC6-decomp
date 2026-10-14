char * __cdecl decorate_backreference(char *out,int arg)

{
  char *pcVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (g_decorate_template_arg_backref_count != 0) {
    piVar2 = &g_decorate_template_arg_backrefs;
    do {
      if (arg == *piVar2) {
        if ((uVar4 < g_decorate_template_arg_backref_count) &&
           (arg == (&g_decorate_template_arg_backrefs)[uVar4])) {
          *out = (char)uVar4 + '0';
          return out + 1;
        }
        break;
      }
      uVar4 = uVar4 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar4 < g_decorate_template_arg_backref_count);
  }
  bVar3 = *(byte *)(arg + 0xc) & 3;
  if (bVar3 == 0) {
    if (((*(c1_type **)(arg + 0x10))->code & 0x800) == 0) {
      pcVar1 = decorate_type_code_2(out,*(c1_type **)(arg + 0x10));
    }
    else {
      *out = '$';
      out[1] = 'D';
      pcVar1 = decorate_number(out + 2,(int)*(short *)(*(int *)(arg + 0x10) + 8));
    }
  }
  else {
    pcVar1 = out;
    if (bVar3 == 1) {
      *out = '$';
      pcVar1 = decorate_template_constant_argument(out + 1,*(c1_node **)(arg + 0x10));
    }
  }
  if ((g_decorate_template_arg_backref_count < 10) && (1 < (int)pcVar1 - (int)out)) {
    (&g_decorate_template_arg_backrefs)[g_decorate_template_arg_backref_count] = arg;
    g_decorate_template_arg_backref_count = g_decorate_template_arg_backref_count + 1;
  }
  return pcVar1;
}

