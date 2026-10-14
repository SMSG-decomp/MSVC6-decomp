void __fastcall try_mul_decomposition_step(int n,c2_mul_decomp *best,int op)

{
  uint32_t uVar1;
  uint uVar2;
  c2_mul_decomp *pcVar3;
  uint budget;
  
  uVar1 = g_mul_decomp_op_cost[op];
  budget = best->cost - uVar1;
  pcVar3 = find_mul_decomposition(n,budget);
  if ((pcVar3->from != (c2_mul_decomp *)0x0) && (uVar2 = pcVar3->cost, uVar2 < budget)) {
    best->from = pcVar3;
    best->op = op;
    best->cost = uVar2 + uVar1;
  }
  return;
}

