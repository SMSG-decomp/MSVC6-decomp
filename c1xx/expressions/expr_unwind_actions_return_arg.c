c1_node * __cdecl expr_unwind_actions_return_arg(byte *frame)

{
  return *(c1_node **)(frame + 8);
}

