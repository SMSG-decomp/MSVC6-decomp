void __cdecl decl_define_variable(c1_symbol *sym)

{
  ushort uVar1;
  c1_node *pcVar2;
  uint uVar3;
  
  if ((sym->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar3 = sym->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym->entity = uVar3 & 0xffffff ^ sym->entity;
  }
  sym->flags3 = sym->flags3 | 4;
  decl_begin_initialized_definition(sym);
  uVar1 = sym->type->code;
  if ((((byte)uVar1 & 0x8f) != 0x83) && ((uVar1 & 0x200) == 0)) {
    pcVar2 = tree_new_int_constant(0);
    decl_finish_initialization(sym,pcVar2);
    return;
  }
  init_begin(sym);
  pcVar2 = tree_new_int_constant(0);
  init_process_initializer(pcVar2);
  init_finish(sym);
  return;
}

