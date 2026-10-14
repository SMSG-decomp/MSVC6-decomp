c1_function_params * __cdecl type_function_intern(c1_function_params *params)

{
  int iVar1;
  uint *puVar2;
  c1_function_params *pcVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  bool bVar7;
  uint *entry;
  uint word6;
  uint **bucket;
  
  iVar1 = params->list->count;
  uVar4 = (uint)(*(ushort *)&params->this_type >> 2) + ((uint)params->list >> 2) & 0x3ff;
  bucket = g_function_params_hash + uVar4;
  puVar6 = (uint *)0x0;
  for (puVar2 = g_function_params_hash[uVar4]; puVar2 != (uint *)0x0; puVar2 = (uint *)*puVar2) {
    if (iVar1 <= *(int *)puVar2[4]) {
      if (iVar1 < *(int *)puVar2[4]) break;
      iVar5 = 4;
      bVar7 = true;
      pcVar3 = params;
      puVar6 = puVar2;
      do {
        puVar6 = puVar6 + 1;
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar7 = (c1_type *)*puVar6 == pcVar3->this_type;
        pcVar3 = (c1_function_params *)&pcVar3->default_count;
      } while (bVar7);
      if (bVar7) {
        return (c1_function_params *)(puVar2 + 1);
      }
    }
    puVar6 = puVar2;
  }
  if (g_function_params_pool_left < 0x14) {
    pool_reserve((c1xx_pool *)&g_function_params_pool,0x14);
  }
  entry = g_function_params_pool;
  g_function_params_pool_left = g_function_params_pool_left - 0x14;
  pcVar3 = (c1_function_params *)(g_function_params_pool + 1);
  g_function_params_pool = g_function_params_pool + 5;
  pcVar3->this_type = params->this_type;
  entry[2] = *(uint *)&params->default_count;
  entry[3] = (uint)params->defaults;
  word6 = (uint)params->list;
  *entry = (uint)puVar2;
  entry[4] = word6;
  if (puVar6 == (uint *)0x0) {
    *bucket = entry;
    return pcVar3;
  }
  *puVar6 = (uint)entry;
  return pcVar3;
}

