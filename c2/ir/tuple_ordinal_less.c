int __fastcall tuple_ordinal_less(c2_tuple *a,c2_tuple *b)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1._0_1_ = a->flags12;
  uVar1._1_1_ = a->flags13;
  uVar2._0_1_ = b->flags12;
  uVar2._1_1_ = b->flags13;
  return (uint)(uVar1 < uVar2);
}

