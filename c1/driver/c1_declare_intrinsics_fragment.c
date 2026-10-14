void __cdecl
c1_declare_intrinsics_fragment
          (c1_u16 return_code,int zero,int row_offset,c1_symbol *sym,char **name_cursor,
          char **letter_end)

{
  c1_u16 return_code_00;
  ushort uVar1;
  char cVar2;
  int iVar3;
  fe_name *name;
  c1_symbol *sym_00;
  c1_type *pcVar4;
  uint uVar5;
  uint uVar6;
  ushort flags;
  char *pcVar7;
  char *pcVar8;
  char cStack00000014;
  ushort in_stack_0000001c;
  ushort in_stack_0000001e;
  c1_type *in_stack_00000020;
  c1_u16 cStack0000002c;
  ushort uStack0000002e;
  char in_stack_0000003c;
  
  return_code_00 = return_code;
  if ((return_code & 0x1000) == 0) {
    return_code_00 = return_code | 0x2000;
  }
  do {
    cStack0000002c = return_code_00;
    flags = (ushort)zero;
    uStack0000002e = flags;
    pcVar4 = type_intern((c1_type *)&stack0x0000002c);
    uVar1 = *(ushort *)((int)&g_intrinsic_table[0].return_layer + row_offset);
    if (uVar1 != flags) {
      in_stack_0000001e = decl_apply_default_calling_convention(uVar1 & 0x8f,flags);
      in_stack_0000001c = *(byte *)((int)&g_intrinsic_table[0].return_layer + row_offset) & 0x8f;
      in_stack_00000020 = pcVar4;
      pcVar4 = type_intern((c1_type *)&stack0x0000001c);
    }
    pcVar4 = type_new_function_returning(1,pcVar4);
    sym->type = pcVar4;
    (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,sym);
    if (g_browse_file != (char *)zero) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,sym);
    }
    if ((*(byte *)((int)&g_intrinsic_table[0].attributes + row_offset) & 0x80) == 0x80) {
      sym->flags3 = sym->flags3 | 1;
    }
    do {
      name_cursor = name_cursor + 1;
      if (name_cursor == letter_end) {
        do {
          iVar3 = _cStack00000014 + 1;
          if (0x1b < iVar3) {
            return;
          }
          name_cursor = &g_intrinsic_names + g_intrinsic_letter_ranges[_cStack00000014 + 1];
          letter_end = &g_intrinsic_names + g_intrinsic_letter_ranges[_cStack00000014 + 2];
          _cStack00000014 = iVar3;
        } while (name_cursor == letter_end);
      }
      iVar3 = (int)(name_cursor + -0x4195556) >> 2;
    } while (((g_opt_MT != zero) && (g_intrinsic_table[iVar3].x0a == flags)) ||
            (cVar2 = intrinsic_is_enabled(iVar3), cVar2 == '\0'));
    in_stack_0000003c = cStack00000014 + '_';
    uVar5 = 0xffffffff;
    pcVar7 = *name_cursor;
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = &stack0x0000003d;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    name = name_intern(&stack0x0000003c);
    sym = sym_take_free_record(6,name,zero);
    if (sym == (c1_symbol *)zero) {
      sym_00 = arena_alloc(g_arenas,g_symbol_size_table[6] + 3 & 0xfffffffc);
      if (sym_00 == (c1_symbol *)zero) {
        sym = (c1_symbol *)0x0;
      }
      else {
        sym = sym_init_kind(sym_00,'\x06',name,zero);
      }
    }
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar5 = sym->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym->entity = uVar5 & 0xffffff ^ sym->entity;
    intrinsic_mark_function(sym,iVar3);
    row_offset = iVar3 * 0xc;
    return_code_00 = g_intrinsic_table[iVar3].return_code;
    if ((((return_code_00 & 0xfff) == 0x11) && (g_ms_extensions != (c1_u8)zero)) &&
       (g_opt_J_unsigned_char != (c1_u8)zero)) {
      c1_declare_intrinsics_fragment(return_code_00,zero,row_offset,sym,name_cursor,letter_end);
      return;
    }
  } while( true );
}

