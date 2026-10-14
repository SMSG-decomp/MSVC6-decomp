int __fastcall test_narrowing_ok(c2_tuple *t,uint32_t size)

{
  int iVar1;
  
  if (t->op == 0x33) {
    iVar1 = narrowing_preserves_value(t,size);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

