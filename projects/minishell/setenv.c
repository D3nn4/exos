#include "ft.h"
#include "minishell.h"

void addVarEnv(t_env *env, char *var, char *value)
{
	int size = 0;
	int new_size = 0;
	char **new_env = NULL;
	while (env->raw_env != NULL)
		size++;
	new_size = size + 2;
	new_env = realloc(env->raw_env, sizeof(*new_env) * new_size);




}
void mySetenv (t_function *data, t_env *env)
{
	// si pas d'argument afficher env
	if (data->args == NULL){
		printf("toto\n");
		displayEnv(env);
		return;
	}

	// separer nom variable et valeur 
	// verifier si elle existe
	// si oui modifier contenue 
	// si non la creer et mettre contenu si pas de vasleur, = null
	addVarEnv(t_env *env, "test", "toto");


	// exporter vers subshells

}