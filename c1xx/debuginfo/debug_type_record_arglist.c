int __cdecl debug_type_record_arglist(int fn_info)

{
  ushort *puVar1;
  uint *puVar2;
  uint uVar3;
  c1_u32 cVar4;
  int iVar5;
  c1_type **param;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar2 = g_debug_index_queue;
  iVar5 = *(int *)(*(int *)(fn_info + 0xc) + 4);
  if (iVar5 == 0) {
    param = (c1_type **)(*(int *)(fn_info + 0xc) + 8);
    uVar3 = type_function_param_count((c1_function_params *)fn_info);
    puVar1 = g_cv_record_body;
    for (uVar7 = uVar3; g_cv_record_body = puVar1, uVar7 != 0; uVar7 = uVar7 - 1) {
      cVar4 = debug_type_index(*param);
      param = param + 1;
      *g_debug_index_queue = cVar4;
      g_debug_index_queue = g_debug_index_queue + 1;
      puVar1 = g_cv_record_body;
    }
    if (0xfafd < uVar3 * 4 + 6) {
      diag_fatal_simple(0x43);
    }
    *puVar1 = 0x1201;
    *(uint *)(puVar1 + 1) = uVar3;
    puVar6 = puVar2;
    puVar8 = (uint *)(puVar1 + 3);
    for (uVar7 = uVar3 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(char *)puVar8 = (char)*puVar6;
      puVar6 = (uint *)((int)puVar6 + 1);
      puVar8 = (uint *)((int)puVar8 + 1);
    }
    g_debug_index_queue = puVar2;
    iVar5 = cvserver_emit_type((short)uVar3 * 4 + 6);
    *(int *)(*(int *)(fn_info + 0xc) + 4) = iVar5;
    iVar5 = *(int *)(*(int *)(fn_info + 0xc) + 4);
  }
  return iVar5;
}

