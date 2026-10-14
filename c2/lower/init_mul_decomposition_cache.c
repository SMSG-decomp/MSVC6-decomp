void init_mul_decomposition_cache(void)

{
  uint32_t uVar1;
  c2_mul_decomp *unit;
  c2_mul_decomp *seed;
  int iVar2;
  c2_mul_decomp **ppcVar3;
  
  ppcVar3 = g_mul_decomp_hash;
  for (iVar2 = 0x1ff; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppcVar3 = (c2_mul_decomp *)0x0;
    ppcVar3 = ppcVar3 + 1;
  }
  unit = mul_decomp_lookup(1);
  unit->from = unit;
  unit->op = 0;
  unit->cost = 0;
  seed = mul_decomp_lookup(-1);
  uVar1 = g_mul_decomp_op_cost[1];
  seed->from = unit;
  seed->cost = uVar1;
  seed->op = 1;
  seed = mul_decomp_lookup(2);
  uVar1 = g_mul_decomp_op_cost[8];
  seed->from = unit;
  seed->op = 8;
  seed->cost = uVar1;
  seed = mul_decomp_lookup(4);
  uVar1 = g_mul_decomp_op_cost[10];
  seed->from = unit;
  seed->cost = uVar1;
  seed->op = 10;
  seed = mul_decomp_lookup(8);
  uVar1 = g_mul_decomp_op_cost[0xc];
  seed->from = unit;
  seed->op = 0xc;
  seed->cost = uVar1;
  seed = mul_decomp_lookup(3);
  uVar1 = g_mul_decomp_op_cost[9];
  seed->from = unit;
  seed->cost = uVar1;
  seed->op = 9;
  seed = mul_decomp_lookup(5);
  uVar1 = g_mul_decomp_op_cost[0xb];
  seed->from = unit;
  seed->op = 0xb;
  seed->cost = uVar1;
  seed = mul_decomp_lookup(9);
  uVar1 = g_mul_decomp_op_cost[0xd];
  seed->from = unit;
  seed->op = 0xd;
  seed->cost = uVar1;
  return;
}

