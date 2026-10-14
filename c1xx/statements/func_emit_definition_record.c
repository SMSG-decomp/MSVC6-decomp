void __cdecl func_emit_definition_record(c1xx_function_record *rec)

{
  c1_u32 *sym;
  byte *pbVar1;
  char cVar2;
  short sVar3;
  c1_sym_link *symref;
  c1_symbol *pcVar4;
  c1_type *type;
  byte bVar5;
  c1_u32 cVar6;
  char *name;
  int iVar7;
  char local_400 [1023];
  char flag;
  
  il_emit_source_file(rec->source_file);
  symref = rec->symbol_entry;
  sym = &symref[-1].position;
  if ((symref[-1].position & 0x80000) != 0) {
    return;
  }
  g_function_compile_it = '\0';
  g_function_in_pch = (byte)(rec->flags >> 4) & 1;
  if (((symref->name->flags & 0x40000000) != 0) && (*(short *)((int)&symref[-1].type + 2) == 0)) {
    if ((symref[1].position & 7) == 3) {
      diag_warning(3,8,sym,9);
      *(byte *)&symref[1].position = (byte)symref[1].position & 0xf8 ^ 1;
    }
    if ((symref[1].position & 0x800) == 0) {
      if ((symref[1].position & 0x100) != 0) {
        diag_warning(3,8,sym,0xe);
        *(byte *)((int)&symref[1].position + 1) = *(byte *)((int)&symref[1].position + 1) & 0xfe;
      }
      pbVar1 = (byte *)((int)&symref[-1].type + 1);
      *pbVar1 = *pbVar1 | 0x80;
    }
    else {
      diag_warning(3,8,sym,0xec);
      *(byte *)((int)&symref[1].position + 1) = *(byte *)((int)&symref[1].position + 1) & 0xf6;
      *(byte *)((int)&symref[-1].type + 1) = *(byte *)((int)&symref[-1].type + 1) | 0x80;
    }
    goto LAB_104429ce;
  }
  bVar5 = (byte)symref[1].position;
  if (((bVar5 & 7) != 3) || ((symref[-1].position & 0x400) != 0)) {
    cVar6 = symref[1].position;
    if ((cVar6 & 0x100) == 0) {
      if ((*(byte *)((int)&symref[2].type + 1) & 0xc) == 0) goto LAB_104429ce;
    }
    else {
      *(byte *)&symref[1].position = bVar5 | 0x40;
      if (((symref[1].position & 0x80000) == 0) &&
         (((cVar6 & 0x1000) != 0 ||
          ((((symref[1].position & 0x40000) != 0 && (g_opt_noexpinl == '\0')) &&
           ((g_function_in_pch == '\0' ||
            (((g_pch_automatic != '\0' || (g_pch_creating != 0)) || (g_auto_pch_using != 0))))))))))
      {
LAB_104429ce:
        g_function_compile_it = '\x01';
      }
    }
  }
  if ((symref[1].position & 0x8000) != 0) {
    g_function_compile_it = '\x01';
  }
  if (g_opt_BforceInst == '\0') {
    if (g_function_compile_it == '\0') {
LAB_10442901:
      if (((uint)symref[1].name & 3) == 0) {
        if (g_c9il_mode == '\0') {
          bVar5 = (byte)*sym & 0x1f;
          if (((bVar5 == 7) || (bVar5 == 8)) &&
             (sVar3 = *(short *)((int)&symref[-1].type + 2), sVar3 != 0)) {
            _snprintf(local_400,0x400,"%s::%s",g_scope_vector->entries[sVar3]->name->text,
                      symref->name->text);
            flag = '\0';
            name = local_400;
          }
          else {
            name = symref->name->text;
          }
          iVar7 = (*g_idb->vtbl->idb_has_name)(g_idb,name);
          if (iVar7 != 0) goto LAB_1044290b;
        }
        diag_warning(4,(-(uint)((symref[1].position & 0x100) != 0) & 9) + 0x1f9,sym);
        goto LAB_104429a0;
      }
    }
  }
  else if (g_function_compile_it == '\0') {
    sVar3 = *(short *)((int)&symref[-1].type + 2);
    if (((sVar3 == 0) || ((g_scope_vector->entries[sVar3]->kind & 0x1f) != 4)) ||
       ((((g_scope_vector->entries[sVar3]->detail).cls)->flags3f & 1) == 0)) goto LAB_10442901;
    g_function_compile_it = '\x01';
  }
LAB_1044290b:
  g_function_ex_offset = rec->ex_offset;
  g_function_sy_offset = rec->sy_offset;
  g_function_tuple_count = rec->tuple_count;
  g_function_start_line = rec->start_line;
  g_function_formal_count = rec->formal_count;
  g_function_auto_inline = rec->flags & 1;
  g_function_has_body = 1;
  g_function_not_inlinable = rec->flags >> 2 & 1;
  g_function_il_reused = (byte)(rec->flags >> 5) & 1;
  if (g_opt_Zi != '\0') {
    if ((symref[-1].position & 0x400) == 0) {
      free_list_push_124c((c1_symbol *)sym);
      type = (symref->type).type;
      if (g_opt_Zg == '\0') {
        debug_type_index(type);
        cVar2 = (char)type->code;
        while (cVar2 < '\0') {
          type = type->base;
          cVar2 = (char)type->code;
        }
        if (((((type->code & 0x300) != 0) &&
             (pcVar4 = (type->extra).cls, pcVar4 != (c1_symbol *)0x0)) &&
            ((pcVar4->kind & 0x1f) == 4)) && (((pcVar4->detail).cls)->debug_index == 0)) {
          debug_emit_class_type(pcVar4);
        }
      }
      free_list_pop_124c();
    }
    else {
      pcVar4 = g_scope_vector->entries[*(short *)((int)&symref[-1].type + 2)];
      cVar6 = debug_emit_class_type(pcVar4);
      pcVar4->type->debug_index = cVar6;
    }
  }
  il_emit_symbol_with_mode(0xe,(int)symref,g_function_compile_it);
LAB_104429a0:
  *(byte *)((int)&symref[-1].position + 2) = *(byte *)((int)&symref[-1].position + 2) | 8;
  return;
}

