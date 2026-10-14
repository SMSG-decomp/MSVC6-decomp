void __thiscall
il_symbol_pair_operand_keys(c1_catch_handler *handler,uint *key1,uint *key2,uint *flags)

{
  byte bVar1;
  uint uVar2;
  c1_symbol *pcVar3;
  c1_symbol *pcVar4;
  
  if (handler == (c1_catch_handler *)0x0) {
    *key1 = 0;
    *key2 = 0;
    return;
  }
  pcVar4 = handler->variable;
  if (pcVar4 == (c1_symbol *)0x0) {
    *key1 = 0;
  }
  else if (g_c9il_mode == '\0') {
    if ((pcVar4->key_ref & 0xfffffff8) == 0) {
      uVar2 = il_symbol_key_assign(pcVar4);
      *key1 = uVar2;
    }
    else {
      *key1 = pcVar4->key_ref >> 3;
    }
  }
  else {
    *key1 = pcVar4->entity & 0xffffff;
  }
  pcVar4 = handler->type_descriptor;
  if (pcVar4 == (c1_symbol *)0x0) {
    uVar2 = 0;
    goto LAB_104a9e92;
  }
  if ((pcVar4->kind & 0x1f) == 8) {
    sym_mark_enclosing_scopes(pcVar4);
  }
  sym_mark_referenced(pcVar4);
  if ((pcVar4->flags4 & 0x40) == 0) {
    bVar1 = pcVar4->kind & 0x1f;
    if ((bVar1 == 7) || (bVar1 == 8)) {
      if ((*(byte *)((int)&pcVar4->tail + 10) & 0x80) != 0) {
        sym_redeclaration_group_add(&g_map_region_queue,pcVar4);
      }
      if ((*(byte *)((int)&pcVar4->tail + 9) & 2) != 0) {
        pcVar3 = class_scalar_deleting_dtor_of(pcVar4);
        goto LAB_104a9e2f;
      }
    }
  }
  else {
    bVar1 = pcVar4->kind & 0x1f;
    if (bVar1 == 3) {
      pcVar3 = sym_static_member_stand_in(pcVar4);
      pcVar4 = pcVar3;
    }
    else if (bVar1 == 10) {
      pcVar3 = sym_inline_instance_of(pcVar4);
      pcVar4 = pcVar3;
    }
    else {
      pcVar4 = (c1_symbol *)0x0;
      pcVar3 = (c1_symbol *)0x0;
    }
LAB_104a9e2f:
    sym_mark_referenced(pcVar3);
  }
  if (((((pcVar4->flags23 & 1) != 0) &&
       (pcVar3 = sym_segment_record(pcVar4), (pcVar3->entity & 0xffffff) == 5)) &&
      (g_current_function != (c1_symbol *)0x0)) && ((g_current_function->flags21 & 1) == 0)) {
    g_function_has_body = 1;
    g_function_auto_inline = 0;
  }
  if (g_c9il_mode == '\0') {
    if ((pcVar4->key_ref & 0xfffffff8) == 0) {
      uVar2 = il_symbol_key_assign(pcVar4);
    }
    else {
      uVar2 = pcVar4->key_ref >> 3;
    }
  }
  else {
    uVar2 = pcVar4->entity & 0xffffff;
  }
LAB_104a9e92:
  *key2 = uVar2;
  bVar1 = (byte)handler->cv;
  uVar2 = (uint)((bVar1 >> 5 & 1) != 0);
  if ((bVar1 >> 6 & 1) != 0) {
    uVar2 = uVar2 | 2;
  }
  if ((char)bVar1 < '\0') {
    uVar2 = uVar2 | 4;
  }
  if ((handler->flags & 1) != 0) {
    uVar2 = uVar2 | 8;
  }
  *flags = uVar2;
  return;
}

