int __cdecl asm_check_member_operand(void *name)

{
  char cVar1;
  ushort uVar2;
  c1_type *pcVar3;
  c1_u8 cVar4;
  c1_type *pcVar5;
  c1_symbol *pcVar6;
  int iVar7;
  byte bVar8;
  
  if ((g_asm_member_struct == (void *)0x0) || (*(int *)((int)g_asm_member_struct + 0x34) == 0)) {
    pcVar6 = g_asm_operand->expr->sym;
    if ((pcVar6 == (c1_symbol *)0x0) || ((g_asm_operand->expr->kind & 1) == 0)) {
      if (g_asm_operand->frame_sym != (c1_symbol *)0x0) {
        pcVar5 = g_asm_operand->frame_sym->type;
        cVar1 = (char)pcVar5->code;
        while (cVar1 < '\0') {
          pcVar5 = pcVar5->base;
          cVar1 = (char)pcVar5->code;
        }
        uVar2 = pcVar5->code;
        goto LAB_1064eff3;
      }
      if (g_asm_operand->sym != (c1_symbol *)0x0) {
        pcVar5 = g_asm_operand->sym->type;
        cVar1 = (char)pcVar5->code;
        while (cVar1 < '\0') {
          pcVar5 = pcVar5->base;
          cVar1 = (char)pcVar5->code;
        }
        if ((pcVar5->code & 0x200) == 0) goto LAB_1064f132;
        goto LAB_1064eff9;
      }
    }
    else {
      pcVar5 = pcVar6->type;
      cVar1 = (char)pcVar5->code;
      while (cVar1 < '\0') {
        pcVar5 = pcVar5->base;
        cVar1 = (char)pcVar5->code;
      }
      uVar2 = pcVar5->code;
LAB_1064eff3:
      if ((uVar2 & 0x200) != 0) {
LAB_1064eff9:
        g_asm_member_struct = (pcVar5->extra).sym;
        goto LAB_1064f001;
      }
    }
LAB_1064f132:
    g_asm_member_struct = (void *)0x0;
  }
  else {
LAB_1064f001:
    if ((g_asm_member_struct != (void *)0x0) && (*(int *)((int)g_asm_member_struct + 0x34) != 0)) {
      pcVar6 = sym_chain_find_name((c1_symbol *)
                                   (*(int *)(*(int *)((int)g_asm_member_struct + 0x34) + 4) + -8),
                                   name);
      goto LAB_1064f028;
    }
  }
  pcVar6 = scope_stack_lookup_anonymous_member(g_current_scope,(int)name);
LAB_1064f028:
  if (((((pcVar6 == (c1_symbol *)0x0) || (bVar8 = pcVar6->kind & 0x1f, bVar8 == 0)) || (0xe < bVar8)
       ) || ((bVar8 == 5 || ((bVar8 != 2 && (bVar8 != 3)))))) || ((pcVar6->storage & 7) == 3)) {
    iVar7 = asm_operand_description_id();
    diag_error(0x19b,name,iVar7);
    return 0;
  }
  pcVar5 = pcVar6->type;
  cVar1 = (char)pcVar5->code;
  pcVar3 = pcVar5;
  while (cVar1 < '\0') {
    pcVar3 = pcVar3->base;
    cVar1 = (char)pcVar3->code;
  }
  if ((pcVar3->code & 0x200) == 0) {
    if (bVar8 == 2) {
      diag_warning(1,0x191,pcVar6);
    }
    iVar7 = asm_symbol_operand_size(pcVar6);
    cVar4 = asm_size_class_of_bytes(iVar7);
    g_asm_operand->size_class = cVar4;
  }
  else {
    cVar1 = (char)pcVar5->code;
    while (cVar1 < '\0') {
      pcVar5 = pcVar5->base;
      cVar1 = (char)pcVar5->code;
    }
    if ((pcVar5->code & 0x200) != 0) {
      g_asm_member_struct = (pcVar5->extra).sym;
      return (int)pcVar6->detail;
    }
  }
  g_asm_member_struct = (void *)0x0;
  return (int)pcVar6->detail;
}

