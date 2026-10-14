void __fastcall rmw_dispatch_then_const(c2_tuple *t)

{
  uint64_t uVar1;
  
  uVar1 = dispatch_rmw_by_op(t);
  operand_new_intconst(t->type,(uint32_t)uVar1,(int32_t)(uVar1 >> 0x20));
  return;
}

