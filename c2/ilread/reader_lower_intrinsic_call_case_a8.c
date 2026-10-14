c2_tuple *
reader_lower_intrinsic_call_case_a8
          (c2_tuple *call,c2_function *fn,c2_tuple *anchor,c2_operand *result)

{
  c2_tuple *pcVar1;
  
  intrinsic_convert_arguments(call);
  reader_lower_eh_intrinsic(fn,anchor);
  result = anchor->dst;
  pcVar1 = convert_operand(&result,0x1004,&anchor);
  return pcVar1;
}

