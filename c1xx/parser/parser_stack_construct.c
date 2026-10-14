void * __fastcall parser_stack_construct(int *stack)

{
  parser_stack_zero_header(stack);
  return stack;
}

