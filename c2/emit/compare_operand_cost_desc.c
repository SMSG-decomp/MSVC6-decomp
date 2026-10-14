int __fastcall compare_operand_cost_desc(void *a,void *b)

{
  if (*(uint *)((int)b + 0xc) <= *(uint *)((int)a + 0xc)) {
    return -(uint)(*(uint *)((int)a + 0xc) != *(uint *)((int)b + 0xc));
  }
  return 1;
}

