from newsapi import NewsApiClient
from datetime import datetime, timedelta
import json

# Inicialização do cliente da API de notícias com sua chave de API
newsapi = NewsApiClient(api_key='13bd279cd7c54b65ac7359a91ae47bc6')

def get_news_by_category_and_country(categories, country):
    # Calcula as datas de início e fim para os últimos 7 dias
    start_date = (datetime.now() - timedelta(days=7)).strftime('%Y-%m-%d')
    end_date = datetime.now().strftime('%Y-%m-%d')
    
    # Prepara a string de categorias para a consulta, se necessário
    # Este passo depende de como a API espera receber as categorias
    # Por exemplo, se a API espera uma lista, você pode precisar ajustar este código
    
    # Faz a chamada à API para buscar notícias com os parâmetros fornecidos
    all_articles = newsapi.get_everything(q=categories,
                                           from_param=start_date,
                                           to=end_date,
                                           language='en',
                                           sort_by='relevancy',
                                           page_size=10,
                                           page=1)
    
    # Converte o resultado para JSON e retorna
    return json.dumps(all_articles)

# Exemplo de uso da função
if __name__ == "__main__":
    categories = "technology"
    country = "us"  # Note que este parâmetro pode não ser usado dependendo da função da API
    return_data = get_news_by_category_and_country(categories, country)
    print(return_data)