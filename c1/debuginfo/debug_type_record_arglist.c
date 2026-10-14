int __cdecl debug_type_record_arglist(c1_param_list *params)

{
  ushort *puVar1;
  uint *puVar2;
  uint uVar3;
  c1_u32 cVar4;
  int iVar5;
  c1_type **ppcVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  
  puVar2 = g_debug_index_queue;
  iVar5 = params->debug_index;
  if (iVar5 == 0) {
    ppcVar6 = params->types;
    uVar3 = type_function_param_count(params);
    puVar1 = g_cv_record_body;
    for (uVar8 = uVar3; g_cv_record_body = puVar1, uVar8 != 0; uVar8 = uVar8 - 1) {
      cVar4 = debug_type_index(*ppcVar6);
      ppcVar6 = ppcVar6 + 1;
      *g_debug_index_queue = cVar4;
      g_debug_index_queue = g_debug_index_queue + 1;
      puVar1 = g_cv_record_body;
    }
    if (0xfafd < uVar3 * 4 + 6) {
      diag_fatal_simple(0x43);
    }
    *puVar1 = 0x1201;
    *(uint *)(puVar1 + 1) = uVar3;
    puVar7 = puVar2;
    puVar9 = (uint *)(puVar1 + 3);
    for (uVar8 = uVar3 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(char *)puVar9 = (char)*puVar7;
      puVar7 = (uint *)((int)puVar7 + 1);
      puVar9 = (uint *)((int)puVar9 + 1);
    }
    g_debug_index_queue = puVar2;
    iVar5 = cvserver_emit_type(uVar3 * 4 + 6);
    params->debug_index = iVar5;
  }
  return iVar5;
}

