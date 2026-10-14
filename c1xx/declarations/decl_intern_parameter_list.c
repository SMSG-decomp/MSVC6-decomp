int * __cdecl decl_intern_parameter_list(int params,int fflags,int defaults,int this_type)

{
  bool bVar1;
  c1_u8 *params_00;
  int iVar2;
  int iVar3;
  c1_type_list *pcVar4;
  c1_function_params *pcVar5;
  c1_u8 cVar6;
  int count;
  
  if (params == 0) {
LAB_10401924:
    *(byte *)(fflags + 1) = *(byte *)(fflags + 1) | 0x40;
    pcVar4 = global_scope_record();
  }
  else {
    count = 0;
    bVar1 = false;
    iVar2 = *(int *)(params + 4);
    if (*(int *)(params + 4) != 0) {
      while( true ) {
        iVar3 = iVar2;
        if (*(c1_type **)(iVar3 + 0xc) == g_type_void) {
          bVar1 = true;
        }
        count = count + 1;
        if ((*(c1_type **)(iVar3 + 0xc))->code == 0x80d) break;
        if ((iVar3 == 0) || (iVar2 = *(int *)(iVar3 + 4), *(int *)(iVar3 + 4) == 0))
        goto LAB_104018bd;
      }
      *(byte *)(fflags + 1) = *(byte *)(fflags + 1) | 0x80;
LAB_104018bd:
      if (bVar1) {
        if (count != 1) {
          diag_error(0x35c);
        }
        *(byte *)(iVar3 + -6) = *(byte *)(iVar3 + -6) | 8;
        goto LAB_10401924;
      }
    }
    pcVar4 = param_type_list_intern(count,(c1_sym_list *)params);
  }
  params_00 = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x10;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  *(c1_type_list **)(params_00 + 0xc) = pcVar4;
  if (defaults != 0) {
    cVar6 = '\0';
    *(int *)(params_00 + 8) = defaults;
    do {
      defaults = *(int *)(defaults + 0x14);
      cVar6 = cVar6 + '\x01';
    } while (defaults != 0);
    params_00[4] = cVar6;
  }
  *(int *)params_00 = this_type;
  pcVar5 = type_function_intern((c1_function_params *)params_00);
  return (int *)pcVar5;
}

