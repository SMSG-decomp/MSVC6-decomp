void __thiscall param_clause_set_cv_qualifiers(c1_param_clause *clause,c1_decl_modifier *cv)

{
  clause->cv = cv->bits;
  clause->cv_based = cv->based;
  return;
}

