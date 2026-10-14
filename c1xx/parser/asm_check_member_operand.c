int __cdecl asm_check_member_operand(fe_name *name)

{
  char cVar1;
  ushort uVar2;
  c1_type *pcVar3;
  c1_u8 cVar4;
  c1_type *pcVar5;
  c1_symbol *pcVar6;
  int iVar7;
  byte bVar8;
  
  if ((g_asm_member_class == (c1_symbol *)0x0) ||
     ((g_asm_member_class->x28).members == (c1_sym_list *)0x0)) {
    pcVar6 = g_asm_current_operand->record->sym;
    if ((pcVar6 == (c1_symbol *)0x0) || ((g_asm_current_operand->record->kind & 1) == 0)) {
      if (g_asm_current_operand->frame_symbol != (c1_symbol *)0x0) {
        pcVar5 = g_asm_current_operand->frame_symbol->type;
        cVar1 = (char)pcVar5->code;
        while (cVar1 < '\0') {
          pcVar5 = pcVar5->base;
          cVar1 = (char)pcVar5->code;
        }
        uVar2 = pcVar5->code;
        goto LAB_104b95e1;
      }
      if (g_asm_current_operand->ref_symbol != (c1_symbol *)0x0) {
        pcVar5 = g_asm_current_operand->ref_symbol->type;
        cVar1 = (char)pcVar5->code;
        while (cVar1 < '\0') {
          pcVar5 = pcVar5->base;
          cVar1 = (char)pcVar5->code;
        }
        if ((pcVar5->code & 0x200) == 0) goto LAB_104b9720;
        goto LAB_104b95e7;
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
LAB_104b95e1:
      if ((uVar2 & 0x200) != 0) {
LAB_104b95e7:
        g_asm_member_class = (pcVar5->extra).cls;
        goto LAB_104b95ef;
      }
    }
LAB_104b9720:
    g_asm_member_class = (c1_symbol *)0x0;
  }
  else {
LAB_104b95ef:
    if ((g_asm_member_class != (c1_symbol *)0x0) &&
       ((g_asm_member_class->x28).enumerators != (c1_symtab *)0x0)) {
      pcVar6 = sym_chain_find_name((c1_symbol *)
                                   (((g_asm_member_class->x28).enumerators)->compare - 8),name);
      goto LAB_104b9616;
    }
  }
  pcVar6 = scope_stack_lookup_anonymous_member(g_current_scope,name);
LAB_104b9616:
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
    g_asm_current_operand->size_class = cVar4;
  }
  else {
    cVar1 = (char)pcVar5->code;
    while (cVar1 < '\0') {
      pcVar5 = pcVar5->base;
      cVar1 = (char)pcVar5->code;
    }
    if ((pcVar5->code & 0x200) != 0) {
      g_asm_member_class = (pcVar5->extra).cls;
      return (int)(pcVar6->detail).cls;
    }
  }
  g_asm_member_class = (c1_symbol *)0x0;
  return (int)(pcVar6->detail).cls;
}

