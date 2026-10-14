c1_u8 * __thiscall decl_declare_formal_parameter(int *scope_stack,c1_declaration *decl)

{
  uchar *puVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  c1_scope_lookup *found;
  c1_symbol *sym;
  uint uVar5;
  void *pvVar6;
  c1_symbol *pcVar7;
  
  pvVar6 = decl->name;
  if ((g_block_depth == '\x02') && (*(char *)(scope_stack[1] + 8) != '\x01')) {
    if (g_function_parameter_scope == (c1_scope_symbol_list *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = g_function_parameter_scope->first;
    }
    for (; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
      if ((void *)*piVar4 == pvVar6) {
        diag_error(0x52,pvVar6);
        puVar1 = g_arenas[3].cur;
        g_arenas[3].cur = g_arenas[3].cur + 8;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (puVar1 == (uchar *)0x0) {
          return (c1_u8 *)0x0;
        }
        pcVar7 = sym_new_from_declarator(decl,-1);
        *(c1_symbol **)puVar1 = pcVar7;
        puVar1[4] = '\0';
        puVar1[5] = '\0';
        puVar1[6] = '\0';
        puVar1[7] = '\0';
        return puVar1;
      }
      if (piVar4 == (int *)0x0) break;
    }
  }
  if (((decl->spec).storage & 7) == 1) {
    found = (c1_scope_lookup *)(**(code **)(*(int *)*scope_stack + 8))(pvVar6);
    if (found == (c1_scope_lookup *)0x0) {
      pcVar7 = (c1_symbol *)0x0;
    }
    else {
      pcVar7 = found->sym;
    }
    if (((pcVar7 != (c1_symbol *)0x0) && (bVar2 = pcVar7->kind & 0x1f, bVar2 != 4)) &&
       ((bVar2 == 0 || (((0xe < bVar2 || (bVar2 == 5)) || ((pcVar7->storage & 7) != 7)))))) {
      g_compile_flags_c8 = g_compile_flags_c8 | 0x2000;
      cVar3 = decl_check_redeclaration(decl,pcVar7);
      if (cVar3 == '\0') {
        sym = sym_new_from_declarator(decl,-1);
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffdfff;
        sym->entity = (pcVar7->entity ^ sym->entity) & 0xffffff ^ sym->entity;
        if (g_c9il_mode == '\0') {
          if ((pcVar7->key_ref & 0xfffffff8) == 0) {
            uVar5 = il_symbol_key_assign(pcVar7);
          }
          else {
            uVar5 = pcVar7->key_ref >> 3;
          }
        }
        else {
          uVar5 = pcVar7->entity & 0xffffff;
        }
        sym->key_ref = sym->key_ref & 7 | uVar5 * 8;
        sym->type = pcVar7->type;
        sym->flags4 = (pcVar7->flags4 ^ sym->flags4) & 4 ^ sym->flags4;
        if ((pcVar7->flags23 & 1) != 0) {
          pvVar6 = sym_segment_record(pcVar7);
          if (pvVar6 == (void *)0x0) {
            sym->flags23 = sym->flags23 & 0xfe;
          }
          else {
            sym_set_segment(sym,pvVar6);
          }
        }
        sym->flags4 = (pcVar7->flags4 ^ sym->flags4) & 1 ^ sym->flags4;
        (**(code **)(*(int *)scope_stack[1] + 4))(sym);
        if ((pcVar7->kind & 0x1f) == 6) {
          sym->storage = sym->storage & 0xf8 ^ 1;
          sym->kind = sym->kind & 0xe6 | 6;
          *(undefined2 *)&sym->detail = *(undefined2 *)&pcVar7->detail;
          *(undefined2 *)((int)&sym->detail + 2) = *(undefined2 *)((int)&pcVar7->detail + 2);
        }
        sym_mark_referenced(pcVar7);
        sym->flags1 = sym->flags1 | 2;
        pcVar7->flags1 = pcVar7->flags1 & 0xfd;
        puVar1 = g_arenas[3].cur;
        g_arenas[3].cur = g_arenas[3].cur + 8;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (puVar1 != (uchar *)0x0) {
          *(c1_symbol **)puVar1 = pcVar7;
          puVar1[4] = '\0';
          puVar1[5] = '\0';
          puVar1[6] = '\0';
          puVar1[7] = '\0';
          return puVar1;
        }
      }
      else {
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffdfff;
      }
    }
  }
  return (c1_u8 *)0x0;
}

