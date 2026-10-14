c1_symbol * __cdecl tmpl_deduce_from_target_type(c1_type *type,c1_symbol *sym,byte resolve_flags)

{
  int *piVar1;
  int argc;
  c1_decl_record *pcVar2;
  c1_type *type_00;
  c1_symbol *sym_00;
  c1_node *pcVar3;
  c1_ovl_candidate *pcVar4;
  byte bVar5;
  int iVar6;
  int *piVar7;
  c1_declarator *d;
  c1_node *list;
  char use_type;
  int flag;
  
  if ((sym->kind & 0x1f) == 0x1a) {
    sym = *(c1_symbol **)sym->type;
  }
  if ((type != (c1_type *)0x0) && (bVar5 = (byte)type->code, (char)bVar5 < '\0')) {
    while ((bVar5 & 0x83) != 0x81) {
      type = type->base;
      bVar5 = (byte)type->code;
    }
    list = (c1_node *)0x0;
    piVar1 = *(int **)(*(int *)(((uint)type & -(uint)((type->code & 0x80) != 0)) + 8) + 0xc);
    piVar7 = piVar1 + 2;
    argc = *piVar1;
    d = (c1_declarator *)g_arenas[5].cur;
    for (iVar6 = argc; iVar6 != 0; iVar6 = iVar6 + -1) {
      g_arenas[5].cur = (c1_u8 *)(d + 1);
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (d == (c1_declarator *)0x0) {
        d = (c1_declarator *)0x0;
      }
      else {
        d->name = g_name_formal;
        d->qualifier = (c1_overload_set *)0x0;
        d->op_token = '\x01';
        d->kind = 4;
        pcVar2 = arena_alloc(g_arenas + 5,0x4c);
        if (pcVar2 == (c1_decl_record *)0x0) {
          d->decl = (c1_decl_record *)0x0;
          d->position = g_token_position;
        }
        else {
          pcVar2 = decl_record_init_default(pcVar2,d->name,d->qualifier);
          d->decl = pcVar2;
          d->position = g_token_position;
        }
      }
      type_00 = (c1_type *)*piVar7;
      bVar5 = (byte)type_00->code;
      if (((char)bVar5 < '\0') && ((bVar5 & 0x8f) == 0x80)) {
        type_00 = type_base(type_00);
      }
      d->type = type_00;
      decl_process_declaration(d);
      flag = 2;
      use_type = '\0';
      sym_00 = sym_new_from_declarator(d,5);
      pcVar3 = tree_new_symbol_ref(sym_00,use_type);
      pcVar3 = tree_new_rvalue(pcVar3);
      list = tree_append_list_item(list,pcVar3,flag);
      piVar7 = piVar7 + 1;
      d = (c1_declarator *)g_arenas[5].cur;
    }
    g_arenas[5].cur = (c1_u8 *)d;
    pcVar4 = ovl_resolve_call(sym,(c1_node *)0x0,list,argc,(int *)0x0,resolve_flags);
    if (pcVar4 != (c1_ovl_candidate *)0x0) {
      if (pcVar4->alias == (c1_symbol *)0x0) {
        return pcVar4->function;
      }
      return pcVar4->alias;
    }
  }
  return (c1_symbol *)0x0;
}

