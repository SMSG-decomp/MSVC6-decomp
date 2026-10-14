char * __cdecl decorate_argument_list(char *out,c1_type *type)

{
  c1_type_list *pcVar1;
  c1_type *type_00;
  bool bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  c1_type **ppcVar7;
  int iVar8;
  
  g_decorate_arglist_depth = g_decorate_arglist_depth + 1;
  pcVar1 = ((type->extra).params)->list;
  iVar4 = pcVar1->count;
  ppcVar7 = pcVar1->types;
  if (((byte)pcVar1->types[0]->code >> 6 & 1) != 0) {
    *out = 'X';
    g_decorate_arglist_depth = g_decorate_arglist_depth + -1;
    return out + 1;
  }
  bVar2 = false;
  iVar8 = g_decorate_arg_backref_count;
  if (iVar4 != 0) {
    do {
      iVar4 = iVar4 + -1;
      if (bVar2) goto LAB_10410e2b;
      type_00 = *ppcVar7;
      if (type_00->code == 0x80d) {
        bVar2 = true;
      }
      else {
        iVar5 = 0;
        if (0 < iVar8) {
          piVar6 = &g_decorate_arg_backrefs;
          do {
            if (type_00 == (c1_type *)*piVar6) {
              if ((iVar5 < iVar8) && (type_00 == (c1_type *)(&g_decorate_arg_backrefs)[iVar5])) {
                *out = (char)iVar5 + 0x30;
                pbVar3 = (byte *)(out + 1);
                goto LAB_10410dbf;
              }
              break;
            }
            iVar5 = iVar5 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar5 < iVar8);
        }
        pbVar3 = decorate_pointer_target(out,type_00,0);
        if ((g_decorate_arg_backref_count < 10) && (1 < (int)pbVar3 - (int)out)) {
          (&g_decorate_arg_backrefs)[g_decorate_arg_backref_count] = *ppcVar7;
          g_decorate_arg_backref_count = g_decorate_arg_backref_count + 1;
        }
LAB_10410dbf:
        ppcVar7 = ppcVar7 + 1;
        out = (char *)pbVar3;
        iVar8 = g_decorate_arg_backref_count;
      }
    } while (iVar4 != 0);
    if (bVar2) {
LAB_10410e2b:
      *out = 0x5a;
      g_decorate_arglist_depth = g_decorate_arglist_depth + -1;
      return out + 1;
    }
  }
  *out = 0x40;
  g_decorate_arglist_depth = g_decorate_arglist_depth + -1;
  return out + 1;
}

