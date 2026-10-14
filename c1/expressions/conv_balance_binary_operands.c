void __cdecl conv_balance_binary_operands(c1_node **left,c1_node **right)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  
  if ((*right != (c1_node *)0x0) && (-1 < (char)(*right)->type->code)) {
    pcVar1 = conv_arithmetic_result_type((*left)->type,right);
    if (pcVar1 != (c1_type *)0x0) {
      pcVar2 = conv_convert_to_type('d',pcVar1,*right);
      *right = pcVar2;
    }
  }
  if ((*left != (c1_node *)0x0) && (-1 < (char)(*left)->type->code)) {
    pcVar1 = conv_arithmetic_result_type((*right)->type,left);
    if (pcVar1 != (c1_type *)0x0) {
      pcVar2 = conv_convert_to_type('d',pcVar1,*left);
      *left = pcVar2;
    }
  }
  return;
}

