#include "ft.h"
#include "minishell.h"


void setenv (t_function *data, t_env *env)
{
	// si pas d'argument afficher env
	if (data->args == NULL){
		displayEnv(env);
		return;
	}
	// separer nom variable et valeur 
	// verifier si elle existe
	// si oui modifier contenue 
	// si non la creer et mettre contenu si pas de vasleur, = null


	// exporter vers subshells

}