void __cdecl tmpl_resolve_function_template_name_token(c1_u8 **token,c1_symbol *qualifier)

{
  fe_name *pfVar1;
  char cVar2;
  uint uVar3;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar4;
  byte *pbVar5;
  c1_arg_list *pcVar6;
  c1_u8 *pcVar7;
  c1_symbol *pcVar8;
  int iVar9;
  uint uVar10;
  uint *src;
  c1_symbol *sym;
  uint *puVar11;
  
  pcVar4 = (c1_lookup_entry *)g_arenas[5].cur;
  uVar3 = g_compile_flags_c8 | 0x20000;
  uVar10 = g_compile_flags_c8 >> 0x11;
  sym = (c1_symbol *)0x0;
  g_compile_flags_c8 = uVar3;
  if (qualifier == (c1_symbol *)0x0) {
    pcVar4 = (c1_lookup_entry *)
             expr_build_member_access_implicit(g_current_scope,*(void **)(*token + 8));
  }
  else if ((qualifier->kind & 0x1f) == 0x19) {
    result = (c1_lookup_result *)
             (**(code **)(**(int **)qualifier->type + 0xc))(*(undefined4 *)(*token + 8),0);
    pcVar4 = lookup_check_ambiguous_symbol(result,'\x01');
  }
  else {
    g_arenas[5].cur = g_arenas[5].cur + 0xc;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar4 == (c1_lookup_entry *)0x0) goto LAB_104b6764;
    pcVar8 = class_current_member_lookup(*(void **)(*token + 8));
    pcVar4->sym = pcVar8;
    *(c1_u8 *)((int)pcVar4 + 4) = '\0';
    *(c1_u8 *)((int)pcVar4 + 5) = '\0';
    *(c1_u8 *)((int)pcVar4 + 6) = '\0';
    *(c1_u8 *)((int)pcVar4 + 7) = '\0';
    *(c1_u8 *)((int)pcVar4 + 8) = '\0';
    *(c1_u8 *)((int)pcVar4 + 9) = '\0';
    *(c1_u8 *)((int)pcVar4 + 10) = '\0';
    *(c1_u8 *)((int)pcVar4 + 0xb) = '\0';
  }
  if (pcVar4 != (c1_lookup_entry *)0x0) {
    sym = pcVar4->sym;
  }
LAB_104b6764:
  if ((uVar10 & 1) == 0) {
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffdffff;
  }
  if (sym != (c1_symbol *)0x0) {
    cVar2 = sym_names_function_template(sym);
    if (cVar2 != '\0') {
      pbVar5 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar5 == 0x44) {
        pcVar6 = parse_reparse_template_arguments((void *)0x0);
        pcVar7 = g_arenas[5].cur;
        if ((pcVar6 != (c1_arg_list *)0x0) && ((pcVar6->flags & 1) == 0)) {
          g_arenas[5].cur = g_arenas[5].cur + 0x10;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar7 == (c1_u8 *)0x0) {
            g_yylval = 0;
            pcVar7 = g_arenas[5].cur;
          }
          else {
            pfVar1 = sym->name;
            pcVar7[4] = '\x01';
            pcVar7[5] = '\0';
            pcVar7[6] = '\0';
            pcVar7[7] = '\0';
            *(fe_name **)pcVar7 = pfVar1;
            *(c1_symbol **)(pcVar7 + 8) = sym;
            *(c1_arg_list **)(pcVar7 + 0xc) = pcVar6;
            g_yylval = (uint)pcVar7;
            pcVar7 = g_arenas[5].cur;
          }
          g_arenas[5].cur = pcVar7 + 0x30;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar7 != (c1_u8 *)0x0) {
            *pcVar7 = 0xe4;
            src = &g_yylval;
            puVar11 = (uint *)(pcVar7 + 8);
            for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar11 = *src;
              src = src + 1;
              puVar11 = puVar11 + 1;
            }
            *token = pcVar7;
            return;
          }
          *token = (c1_u8 *)0x0;
        }
      }
    }
  }
  return;
}

