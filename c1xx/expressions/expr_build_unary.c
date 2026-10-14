int __cdecl expr_build_unary(uint node2,c1_node *list)

{
  ushort uVar1;
  byte bVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  bool bVar5;
  
  if (list == (c1_node *)0x0) {
    return 0;
  }
  pcVar3 = list;
  if ((list->op == 0xe8) &&
     (pcVar3 = property_build_access((c1_u8)node2,list,(c1_node *)0x0), pcVar3 == (c1_node *)0x0)) {
    return 0;
  }
  if (pcVar3->op == 0x98) {
    diag_error(0x113,pcVar3->left);
    return 0;
  }
  if (pcVar3 == (c1_node *)0x0) goto LAB_10412975;
  uVar1 = pcVar3->type->code;
  if (((uVar1 & 0x300) == 0) &&
     (((bVar2 = (byte)uVar1, (char)bVar2 < '\0' || ((uVar1 & 0xfff) != 0x801)) &&
      ((uVar1 & 0xfff) != 0x802)))) {
    if ((-1 < (char)bVar2) || ((bVar2 & 0x8f) != 0x80)) goto LAB_10412975;
    uVar1 = pcVar3->type->base->code;
    if ((uVar1 & 0x300) == 0) {
      if (((char)uVar1 < '\0') || ((uVar1 & 0xfff) != 0x801)) {
        bVar5 = (uVar1 & 0xfff) == 0x802;
      }
      else {
        bVar5 = true;
      }
    }
    else {
      bVar5 = true;
    }
    if (!bVar5) goto LAB_10412975;
  }
  bVar5 = (g_compile_flags_c8 & 4) != 0;
  if (bVar5) {
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffb;
  }
  list = (c1_node *)((uint)list & 0xffffff00);
  pcVar4 = expr_apply_overloaded_operator((c1_u8)node2,pcVar3,(c1_node *)0x0,1,1,(byte *)&list);
  if (bVar5) {
    g_compile_flags_c8 = g_compile_flags_c8 | 4;
  }
  if (pcVar4 != (c1_node *)0x0) {
    return (int)pcVar4;
  }
  if ((char)list != '\0') {
    pcVar3 = expr_build_unary_return_null();
    return (int)pcVar3;
  }
LAB_10412975:
  pcVar3 = expr_build_builtin_unary(node2,pcVar3);
  return (int)pcVar3;
}

