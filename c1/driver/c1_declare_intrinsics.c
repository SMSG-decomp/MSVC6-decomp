void __cdecl c1_declare_intrinsics(void)

{
  c1_u16 return_code;
  char cVar1;
  fe_name *name;
  c1_symbol *pcVar2;
  c1_type *pcVar3;
  uint uVar4;
  uint uVar5;
  int index;
  char *pcVar6;
  char **name_cursor;
  char *pcVar7;
  char **ppcVar8;
  int local_428;
  char **letter_end;
  c1_type local_420;
  c1_type local_410;
  char local_400;
  char local_3ff [1023];
  
  local_428 = 0;
  do {
    name_cursor = &g_intrinsic_names + g_intrinsic_letter_ranges[local_428];
    letter_end = &g_intrinsic_names + g_intrinsic_letter_ranges[local_428 + 1];
    if (name_cursor != letter_end) {
      do {
        index = (int)(name_cursor + -0x4195556) >> 2;
        if (((g_opt_MT == 0) || (g_intrinsic_table[index].x0a != 0)) &&
           (ppcVar8 = name_cursor, cVar1 = intrinsic_is_enabled(index), cVar1 != '\0')) {
          local_400 = (char)local_428 + '_';
          uVar4 = 0xffffffff;
          pcVar6 = *name_cursor;
          do {
            pcVar7 = pcVar6;
            if (uVar4 == 0) break;
            uVar4 = uVar4 - 1;
            pcVar7 = pcVar6 + 1;
            cVar1 = *pcVar6;
            pcVar6 = pcVar7;
          } while (cVar1 != '\0');
          uVar4 = ~uVar4;
          pcVar6 = pcVar7 + -uVar4;
          pcVar7 = local_3ff;
          for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
            *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
            pcVar6 = pcVar6 + 4;
            pcVar7 = pcVar7 + 4;
          }
          for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
            *pcVar7 = *pcVar6;
            pcVar6 = pcVar6 + 1;
            pcVar7 = pcVar7 + 1;
          }
          name = name_intern(&local_400);
          pcVar2 = sym_take_free_record(6,name,0);
          name_cursor = ppcVar8;
          if (pcVar2 == (c1_symbol *)0x0) {
            pcVar2 = arena_alloc(g_arenas,g_symbol_size_table[6] + 3 & 0xfffffffc);
            if (pcVar2 == (c1_symbol *)0x0) {
              pcVar2 = (c1_symbol *)0x0;
              name_cursor = ppcVar8;
            }
            else {
              pcVar2 = sym_init_kind(pcVar2,'\x06',name,0);
              name_cursor = ppcVar8;
            }
          }
          if (0x7ffffffe < g_next_entity_id) {
            diag_fatal_simple(0x37);
          }
          uVar4 = pcVar2->entity ^ g_next_entity_id;
          g_next_entity_id = g_next_entity_id + 1;
          pcVar2->entity = uVar4 & 0xffffff ^ pcVar2->entity;
          intrinsic_mark_function(pcVar2,index);
          return_code = g_intrinsic_table[index].return_code;
          if ((((return_code & 0xfff) == 0x11) && (g_ms_extensions != '\0')) &&
             (g_opt_J_unsigned_char != '\0')) {
            c1_declare_intrinsics_fragment(return_code,0,index * 0xc,pcVar2,name_cursor,letter_end);
            return;
          }
          local_410.base = (c1_type *)0x0;
          local_410.debug_index = 0;
          local_410.flags = 0;
          local_410.extra.sym = (c1_symbol *)0x0;
          local_410.code = return_code;
          pcVar3 = type_intern(&local_410);
          if (g_intrinsic_table[index].return_layer != 0) {
            local_420.flags =
                 decl_apply_default_calling_convention
                           (g_intrinsic_table[index].return_layer & 0x8f,0);
            local_420.code = (byte)g_intrinsic_table[index].return_layer & 0x8f;
            local_420.debug_index = 0;
            local_420.extra.sym = (c1_symbol *)0x0;
            local_420.base = pcVar3;
            pcVar3 = type_intern(&local_420);
          }
          pcVar3 = type_new_function_returning(1,pcVar3);
          pcVar2->type = pcVar3;
          (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,pcVar2);
          if (g_browse_file != (char *)0x0) {
            (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar2);
          }
          if ((g_intrinsic_table[index].attributes & 0x80) == 0x80) {
            pcVar2->flags3 = pcVar2->flags3 | 1;
          }
        }
        name_cursor = name_cursor + 1;
      } while (name_cursor != letter_end);
    }
    local_428 = local_428 + 1;
    if (0x1b < local_428) {
      return;
    }
  } while( true );
}

