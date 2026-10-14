void __thiscall param_clause_set_exception_spec(c1_param_clause *clause,int exception_spec)

{
  *(int *)(clause->pad15 + 3) = exception_spec;
  return;
}

