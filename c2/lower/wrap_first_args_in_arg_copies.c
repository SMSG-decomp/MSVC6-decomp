c2_tuple * __fastcall wrap_first_args_in_arg_copies(c2_tuple *call,int n)

{
  c2_operand *pcVar1;
  c2_tuple *t;
  c2_operand *a;
  int local_4;
  
  a = call->src;
  t = call;
  local_4 = n;
  if (n < 1) {
    return call;
  }
  do {
    pcVar1 = a->next;
    t = emit_op_before_with_parts(0x15a,a->type,a,(c2_operand *)0x0,t);
    tuple_replace_src(call,a,t->dst);
    local_4 = local_4 + -1;
    a = pcVar1;
  } while (local_4 != 0);
  return t;
}

