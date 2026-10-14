int __fastcall iv_tuple_is_add_sub_of(c2_operand *op,c2_symbol *s)

{
  c2_symbol *pcVar1;
  int iVar2;
  
  pcVar1 = (op->u18).reg;
  if ((pcVar1 != (c2_symbol *)0x0) &&
     (((iVar2._0_1_ = pcVar1->cls, iVar2._1_1_ = pcVar1->flags5, iVar2._2_1_ = pcVar1->flags6,
       iVar2._3_1_ = pcVar1->flags7, iVar2 == 0x179 || (iVar2 == 0x17b)) &&
      ((c2_symbol *)pcVar1->part_next->def == s)))) {
    return 1;
  }
  return 0;
}

