void __thiscall class_declare_friend_function(c1_declarator *d,c1_u8 *spec,c1_symbol *cls)

{
  byte bVar1;
  c1_u16 cVar2;
  c1xx_hash_scope *pcVar3;
  c1_symbol *pcVar4;
  byte *pbVar5;
  
  if (spec != (c1_u8 *)0x0) {
    if ((d->flags56 & 2) != 0) {
      pcVar4 = d->sym;
      if (pcVar4 == (c1_symbol *)0x0) {
        pcVar4 = sym_new_from_declarator(d,5);
      }
      diag_error(0xfe,pcVar4);
    }
    if (d->qualifier == (c1_overload_set *)0x0) {
      d->kind = 0;
      pcVar3 = scope_enclosing_namespace(g_current_scope,'\x01');
      if (pcVar3 != (c1xx_hash_scope *)0x0) {
        d->owner = pcVar3->ns;
      }
      pcVar4 = decl_declare_and_check(d,spec);
      d->sym = pcVar4;
      if (pcVar4 == (c1_symbol *)0x0) {
        return;
      }
      if ((pcVar4->flags3 & 4) != 0) {
        return;
      }
    }
    else {
      if ((d->qualifier->list->head->key->sym->kind & 0x1f) == 0x19) {
        d->kind = 3;
      }
      decl_enter_declaration_context(d);
      decl_process_declaration(d);
      if ((d->kind != 7) && (d->kind != 8)) {
        diag_error(0x3f,d->qualifier);
        return;
      }
      pbVar5 = decl_resolve_function_in_overload_set(d);
      if (pbVar5 == (byte *)0x0) {
        d->sym = (c1_symbol *)0x0;
      }
      else {
        d->sym = *(c1_symbol **)(**(int **)(pbVar5 + 0x14) + 8);
      }
      if ((d->sym == (c1_symbol *)0x0) || ((d->kind != 7 && (d->kind != 8)))) {
        diag_error(0xf5,d->qualifier);
        return;
      }
    }
    pcVar4 = d->sym;
    if (((pcVar4->flags1 & 0x10) == 0x10) || ((pcVar4->flags1 & 0x20) == 0x20)) {
      cVar2 = pcVar4->scope_index;
      if ((cVar2 == 0) || (g_scope_vector->entries[(short)cVar2] == cls)) {
        if (cVar2 == 0) {
          pcVar4->scope_index = ((cls->detail).cls)->scope_index;
        }
        pcVar4 = d->sym;
        bVar1 = pcVar4->flags1;
        if (pcVar4 == (c1_symbol *)0x0) {
          pcVar4 = sym_new_from_declarator(d,5);
        }
        diag_error((-(ushort)((bVar1 & 0x10) != 0x10) & 0xfe87) + 0x279,pcVar4);
      }
      else {
        class_add_friend(cls,(c1xx_decl_specifiers *)spec,pcVar4);
      }
    }
    else {
      class_add_friend(cls,(c1xx_decl_specifiers *)spec,pcVar4);
    }
    if (g_browse_file != (char *)0x0) {
      (*g_il_emitter->vtbl->record_d)((int)d->sym);
    }
  }
  return;
}

