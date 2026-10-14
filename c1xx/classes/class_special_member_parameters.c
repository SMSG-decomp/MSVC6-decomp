c1_u8 * __cdecl class_special_member_parameters(int key,int kind,c1_symbol *sym)

{
  int *piVar1;
  c1_u8 *pcVar2;
  c1_type *type;
  void *name;
  int *piVar3;
  int n;
  
  pcVar2 = g_arenas[5].cur;
  switch(kind) {
  case 2:
    pcVar2 = param_list_new_copy_parameter
                       ((c1_symbol *)key,(*(byte *)(*(int *)(key + 0x24) + 0x3d) >> 4 & 3) << 5);
    break;
  case 3:
    pcVar2 = param_list_new_copy_parameter
                       ((c1_symbol *)key,(ushort)(*(byte *)(*(int *)(key + 0x24) + 0x3d) >> 6) << 5)
    ;
    break;
  default:
    goto switchD_10432449_caseD_4;
  case 6:
  case 7:
    g_arenas[5].cur = g_arenas[5].cur + 0x1c;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar2 == (c1_u8 *)0x0) {
      pcVar2 = (c1_u8 *)0x0;
    }
    else {
      pcVar2[0x10] = '\x03';
      pcVar2[0x11] = '\0';
      pcVar2[0x12] = '\0';
      pcVar2[0x13] = '\0';
      pcVar2[0x14] = '\0';
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
    }
    param_list_add_compiler_formal(pcVar2,PTR_104d1628,g_type_unsigned_int);
    break;
  case 8:
    pcVar2 = param_list_new_copy_parameter
                       ((c1_symbol *)key,(*(byte *)(*(int *)(key + 0x24) + 0x3d) >> 4 & 3) << 5);
    break;
  case 0x11:
    g_arenas[5].cur = g_arenas[5].cur + 0x1c;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar2 == (c1_u8 *)0x0) {
      pcVar2 = (c1_u8 *)0x0;
    }
    else {
      pcVar2[0x10] = '\x03';
      pcVar2[0x11] = '\0';
      pcVar2[0x12] = '\0';
      pcVar2[0x13] = '\0';
      pcVar2[0x14] = '\0';
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
    }
    piVar1 = *(int **)(*(int *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8) +
                      0xc);
    piVar3 = piVar1 + 2;
    for (n = *piVar1; n != 0; n = n + -1) {
      type = (c1_type *)*piVar3;
      if ((type->code & 0x200) != 0) {
        type = type_pointer_with_qualifiers(type,0);
      }
      name = name_intern_numbered(n);
      param_list_add_compiler_formal(pcVar2,name,type);
      piVar3 = piVar3 + 1;
    }
  }
  if (pcVar2 != (c1_u8 *)0x0) {
    return pcVar2;
  }
switchD_10432449_caseD_4:
  pcVar2 = class_record_new_kind5();
  return pcVar2;
}

