void __cdecl conv_apply_integral_promotion_2(c1_node **left,c1_node **right)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  
  if ((*right != (c1_node *)0x0) && (-1 < (char)(*right)->type->code)) {
    pcVar1 = conv_integral_promotion_target((*left)->type,right);
    if (pcVar1 != (c1_type *)0x0) {
      pcVar2 = conv_convert_expression('d',pcVar1,*right,'\x02','\0');
      *right = pcVar2;
    }
  }
  if ((*left != (c1_node *)0x0) && (-1 < (char)(*left)->type->code)) {
    pcVar1 = conv_integral_promotion_target((*right)->type,left);
    if (pcVar1 != (c1_type *)0x0) {
      pcVar2 = conv_convert_expression('d',pcVar1,*left,'\x02','\0');
      *left = pcVar2;
    }
  }
  return;
}

