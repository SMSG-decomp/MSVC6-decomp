c1_symbol * __thiscall
decl_check_extern_block_initializer(c1_symbol *sym,byte mask_8,c1_declarator *d,byte *spec)

{
  byte bVar1;
  c1xx_hash_scope *pcVar2;
  int iVar3;
  c1_symbol *pcVar4;
  
  sym->flags3 = sym->flags3 | 4;
  pcVar4 = d->sym;
  if (pcVar4 == (c1_symbol *)0x0) {
    pcVar4 = sym_new_from_declarator(d,5);
  }
  diag_error(0xcd,pcVar4);
  if (d->qualifier != (c1_overload_set *)0x0) {
    pcVar4 = d->qualifier->list->head->sym;
    pcVar2 = scope_enclosing_namespace(g_current_scope,'\x01');
    if (pcVar2 != (c1xx_hash_scope *)0x0) {
      ns_check_definition_scope(&pcVar4->kind,(int)pcVar2->ns);
    }
    if ((g_scope_vector->entries[(short)pcVar4->scope_index]->kind & 0x1f) == 4) {
      iVar3 = sym_is_static_data_member(pcVar4);
      if (iVar3 != 0) {
        if (((g_compile_flags_cc & 4) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) {
          pcVar4 = decl_merge_redeclaration(d->sym,d->qualifier,pcVar4);
          return pcVar4;
        }
        return pcVar4;
      }
      if ((g_compile_flags_c4 & 0x200) != 0) {
        return d->sym;
      }
      diag_error(0x15e,d->qualifier);
    }
  }
  pcVar4 = d->sym;
  if ((((pcVar4->flags22 & mask_8) != 0) && (((pcVar4->flags2 & 4) != 0 || ((d->flags54 & 4) != 0)))
      ) && (((g_compile_flags_c4 & 0x20000) == 0 ||
            (((g_current_function->flags22 & mask_8) == 0 ||
             ((g_current_function->flags21 & 1) == 0)))))) {
    if (pcVar4 == (c1_symbol *)0x0) {
      pcVar4 = sym_new_from_declarator(d,5);
    }
    diag_error(0x1eb,pcVar4,0x179);
  }
  pcVar4 = d->sym;
  bVar1 = pcVar4->storage & 7;
  if (((((bVar1 != 0) && (bVar1 != 7)) && ((*spec & 7) != 1)) && ((d->flags54 & 4) == 0)) &&
     ((((pcVar4->flags2 & 4) == 0 ||
       (pcVar4 = sym_class_needing_init(pcVar4), pcVar4 == (c1_symbol *)0x0)) &&
      ((d->sym->kind & 0x1f) == 10)))) {
    iVar3 = sym_has_reference_type(d->sym);
    if ((char)iVar3 == '\0') {
      if (((d->sym->flags5 & 4) != 0) &&
         (bVar1 = (byte)d->sym->type->base->code, (char)bVar1 < '\0')) {
        pcVar4 = decl_check_reference_initialized(bVar1,d);
        return pcVar4;
      }
    }
    else {
      pcVar4 = d->sym;
      if (pcVar4 == (c1_symbol *)0x0) {
        pcVar4 = sym_new_from_declarator(d,5);
      }
      diag_error(0x212,pcVar4);
    }
    if ((d->sym->flags22 & 2) != 0) {
      pcVar4 = decl_based_variable_tail(d->sym,d);
      return pcVar4;
    }
  }
  decl_assign_data_segment_and_check(d);
  g_file_scope_decl_since_body = 1;
  return d->sym;
}

