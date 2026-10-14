c1_symbol * __cdecl sym_new_alias_record(c1_symbol *sym)

{
  c1_function_params *pcVar1;
  fe_name *name;
  byte bVar2;
  int index;
  int iVar3;
  c1_symbol *pcVar4;
  uint uVar5;
  
  bVar2 = sym->kind & 0x1f;
  if (bVar2 == 7) {
LAB_10431b8e:
    if (bVar2 != 8) goto LAB_10431b5a;
  }
  else if (bVar2 != 8) {
    if (bVar2 != 6) {
      return sym;
    }
    goto LAB_10431b8e;
  }
  if ((*(byte *)((int)&sym->tail + 9) & 0x20) != 0) {
    name = sym->name;
    pcVar4 = sym_take_free_record(0x11,name,0);
    if (pcVar4 == (c1_symbol *)0x0) {
      pcVar4 = arena_alloc(g_arenas,g_symbol_size_table[0x11] + 3 & 0xfffffffc);
      if (pcVar4 == (c1_symbol *)0x0) {
        pcVar4 = (c1_symbol *)0x0;
      }
      else {
        pcVar4 = sym_init_kind(pcVar4,'\x11',name,0);
      }
    }
    bVar2 = (pcVar4->flags1 ^ sym->flags1) & 0x40 ^ pcVar4->flags1;
    pcVar4->flags1 = bVar2;
    bVar2 = (bVar2 ^ sym->flags1) & 0x10 ^ bVar2;
    pcVar4->flags1 = bVar2;
    pcVar4->flags1 = (bVar2 ^ sym->flags1) & 3 ^ bVar2;
    pcVar4->type = (c1_type *)&sym->name;
    pcVar1 = *(c1_function_params **)
              (((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8);
    if (pcVar1->default_count != '\0') {
      decl_check_missing_default_parameter(pcVar1,sym);
    }
    if ((sym->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar5 = sym->entity ^ g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
      sym->entity = uVar5 & 0xffffff ^ sym->entity;
    }
    return pcVar4;
  }
LAB_10431b5a:
  if ((((sym->flags1 & 2) != 0) && (index = intrinsic_lookup_by_name(sym->name), index != -1)) &&
     (iVar3 = intrinsic_is_enabled(index), (char)iVar3 != '\0')) {
    intrinsic_mark_function(sym,index);
  }
  pcVar1 = *(c1_function_params **)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8);
  if (pcVar1->default_count != '\0') {
    decl_check_missing_default_parameter(pcVar1,sym);
  }
  if ((sym->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar5 = sym->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym->entity = uVar5 & 0xffffff ^ sym->entity;
  }
  return sym;
}

